/*
	Создать, развернуть определяемую пользователем скалярную функцию CLR
	
*/
CREATE EXTENSION IF NOT EXISTS plpython3u;

create or replace function get_min_price_houseware()
returns integer as
$$
		res = plpy.execute(f"select min(housewares.price) as min_price\
								from housewares
								where housewares.name = 'A mirror'");
		if res:
				return res[0]['min_age']
$$
language plpython3u;

select * 
from housewares
where animals.name = 'A mirror' and housewares.price = get_min_price_houseware();

/*
	Создать, развернуть пользовательскую агрегатную функцию CLR
	
*/

create or replace function get_count_houseware_by_brand(id_of_brand int)
returns integer as
$$
	count = 0
	result = plpy.execute("select * from housewares");
	if result:
		for elem in result:
			if elem["id_brand"] == id_of_brand:
				count += 1
	return count
$$
language plpython3u;

select get_count_houseware_by_brand(20) as cnt
from housewares
group by cnt;

/*
	Создать, развернуть определяемую пользователем табличную функцию CLR.
*/
create or replace function  find_more_housewares(brand_name_find int)
returns table(result_brand_name text, houseware_count bigint) as
$$
		query = f"select brands.brand_name, count(*) as cnt1\
						from housewares join brands on housewares.id_brand = brands.id_brand \
						having count(*) > (select count(*) as cnt2 \
											from housewares join brands on housewares.id_brand = brands.id_brand
											where brands.brand_name = '{brand_name_find}') \
					 	order by brands.brand_name;"
		result = plpy.execute(query)
		for elem in result:
			yield(elem["brand_name"], elem["cnt1"])
$$

select * from find_more_housewares('Cochran Ltd')


/*
	Создать, развернуть хранимую процедуру CLR
*/

create or replace procedure update_brand_new_country(name_of_brand varchar(30)) as
$$
		plan = plpy.prepare("update brands \
											set country = (select case when country = 'Morocco' then 'America' \
																	when country = 'Bhutan' then 'Hong Kong' end) \
												where brands.brand_name = $1;",
												["varchar"])
		plpy.execute(plan, [name_of_brand])
$$
language plpython3u;

call update_brand_country('Morales-Werner');

/*
	Создать, развернуть триггер CLR
*/

drop trigger if exists delete_cus_new on cus_user;

drop function if exists delete_cus_new();

create or replace view cus_user as
select *
from customers
where id_customer < 50;

create or replace function delete_cus_new()
return trigger as 
$$
		old_firstname = TD["old"]["firstname"]
		plpy.notice(f"Delete customer {old_firstname}")
		
		plpy.execute(f"update cus_user \
								set country = 'unknown'
								where first_name = 'old_firstname';")
		return TD["new"]
$$
language plpython3u;

create trigger delete_cus_new
instead of delete on cus_user
for each row 
execute procedure delete_cus_new()

delete from cus_user as cus
where cus.first_name = 'Kevin';

/*
	Создать, развернуть определяемую пользователем тип данных CLR
	Выписать количество собак.
*/

create type count_brand as
(
	brand varchar,
	count int
);

create or replace function get_count_brand_new(id_of_brand int)
return count_brand as
$$
	plan = plpy.prepare("select id_brand, count(id_brand) \
													from housewares\
													where id_brand = $1\
													group by id_brand;"		
													["int"])
	result = plpy.execute(plan,[id_of_brand])
	
	if result.nrows():
		return (result[0]["id_brand"], result[0]["count"])
$$
language plpython3u;

select * from get_count_brand_new(15);















