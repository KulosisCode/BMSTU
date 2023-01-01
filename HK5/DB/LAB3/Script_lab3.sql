--1.скаларная функция
create or replace function min_age(first_name_cus text) returns integer as
$$
begin 
	return (select min(customers.age) as min_age
	from customers
	where customers.first_name = first_name_cus);
end;
$$
language plpgsql;

select * from customers
where customers.first_name = 'Benjamin' and customers.age = min_age('Benjamin')

--2.подставляемая табличная функция
create or replace function housewares_in_brand(name_of_brand text)
returns table(id_housewares int, h_name text, h_price int)
as 
$$
begin 
	return query
	(
		select housewares.id, housewares.name, housewares.price 
		from housewares join brands on housewares.id_brand = brands.id_brand 
						--join stores on housewares.id_store  = stores.id_store 
		where brands.brand_name  = name_of_brand
	);
end;
$$
language plpgsql;

select * from housewares_in_brand('Sparks LLC');
DROP FUNCTION housewares_in_brand(text) ;

--3.многооператорная табличная функция
create or replace function more_housewares(name_of_brand text)
returns table(result_brand_name text, houseware_count bigint)
as 
$$
begin
		return query
		(
		select brands.brand_name, count(*) as cnt1
		from housewares join brands on housewares.id_brand = brands.id_brand
		group by brands.brand_name
		having count(*) > (select count(*) as cnt2
											from housewares join brands on housewares.id_brand = brands.id_brand
											where brands.brand_name = name_of_brand)
		order by brands.brand_name
		);
end;
$$
language plpgsql;

select * from more_housewares('Mack LLC')

 DROP FUNCTION more_housewares(text)
 
 --4.функция с рекурсивным ОТВ
 drop table if exists employee_table;

create temp table if not exists employee_table
(
	id_e int primary key,
	boss_id int references employee_table(id_e),
	sur_name text
)

insert into employee_table(id_e, boss_id, sur_name)
values
(0, null, 'Aatrox'),
(1, 0, 'Akali'),
(2, 3, 'Alex'),
(3, 0, 'Alishe'),
(4, 2, 'Blender'),
(5, 4, 'Blue'),
(6, 1, 'Bigbang');

create or replace function recursion()
returns table(id_e int, boss_id int,
								sur_name text,
								level int)
as
$$
begin
	return query
	with recursive vs_rec(id_e, boss_id, sur_name, level) as
	(
		select e_t.id_e, e_t.boss_id, e_t.sur_name, 0
		from employee_table as e_t
		where e_t.boss_id is null
		
		union all 
		select employee_table.id_e, employee_table.boss_id, employee_table.sur_name, vs_rec.level + 1
		from vs_rec join employee_table on vs_rec.id_e = employee_table.boss_id
	)
	select * from vs_rec;
end;
$$
language plpgsql;

select * from recursion();

DROP FUNCTION recursion();

--5.хранимая процедура с параметрами или без
drop procedure update_brand_country(name_of_brand text);
create or replace procedure update_brand_country(name_of_brand text) as 
$$
begin
	update brands
	set country = (select case
					when country = 'Japan Ct.' then 'Japan'
					when country = 'Italy' then 'Italy Ct.'
					when country = 'Japan' then 'Japan Ct.'
					end)
	where brands.brand_name  = name_of_brand;
end;
$$
language plpgsql;

call update_brand_country('Carter LLC')

select * from brands where brand_name  = 'Carter LLC'

select * from expired;

	
--6.хранимая процедура с рекурсивным ОТВ
drop procedure if exists define_employee();
drop table if exists employee_table;

create temp table if not exists employee_table
(
	id_e int primary key,
	boss_id int references employee_table(id_e),
	sur_name text
)

insert into employee_table(id_e, boss_id, sur_name)
values
(0, null, 'Aatrox'),
(1, 0, 'Akali'),
(2, 3, 'Alex'),
(3, 0, 'Alishe'),
(4, 2, 'Blender'),
(5, 4, 'Blue'),
(6, 1, 'Bigbang');
 
create temp table if not exists employee_table_result
(
	sur_name text,
	level int
) 

create or replace procedure define_employee() as
$$
begin
	with recursive vs_rec(id_e, boss_id, sur_name, level) as
	(
		select em_t.id_e, em_t.boss_id, em_t.sur_name, 0
		from employee_table as em_t
		where em_t.boss_id is null
	
		union all 
		select em_t.id_e, em_t.boss_id, em_t.sur_name, vs_rec.level + 1
		from vs_rec join employee_table as em_t on vs_rec.id_e = em_t.boss_id
	)
	insert into employee_table_result(sur_name, level)
	select sur_name, level
	from vs_rec;
end;
$$
language plpgsql;

call define_employee();
select * from employee_table_result;

--7.хранимая процедура с курсором
create or replace procedure changeAge(cus_id int, new_Age int) as
$$
declare 
	list record;
	pointer_cursor cursor for
			select * from customers 
			where id_customer = cus_id;
begin 
	open pointer_cursor;
	loop
		fetch pointer_cursor into list;
		exit when not found;
		update customers 
		set age = new_Age
		where customers.id_customer = list. id_customer; 
		
	end loop;
	close pointer_cursor;
	
end
$$
language plpgsql;

call changeAge(10,20);
select * from customers ;

--8.хранимая процедура доступа к метаданным
create or replace procedure get_metadata(db_name text) as
$$
declare
	db_id int;
	db_encoding varchar;
begin
	select pg.oid, pg_encoding_to_char(pg.encoding) 
	from pg_database as pg
	where pg.datname = db_name
	
	into db_id, db_encoding;
	raise notice 'Database: %, DB_ID: %, DB_encoding: %', db_name, db_id, db_encoding;
end;
$$
language plpgsql;

call get_metadata('postgres');

--defend
select * from information_schema.tables
where table_schema  = 'public';


--9.DML триггер AFTER
create or replace function update_customer()
returns trigger as 
$$
begin
		raise notice 'Old: %', old.age;
		raise notice 'New: %', new.age;
		return new;
end
$$
language plpgsql;

create or replace trigger update_customer
after update on customers
for each row
execute procedure update_customer();

update customers
set age = 30
where id_customer < 5;

select * from customers 
order by id_customer; 

drop function update_customer() cascade;

--10.DML триггер INSTEAD OF
drop view if exists cus_view;
create view cus_view
as select * from customers 
where id_customer < 10

create or replace function delete_cus()
returns trigger as 
$$
begin 
		raise notice 'ID: %.', old.id_customer;
	
		update cus_view
		set age = 25
		where id_customer = old.id_customer;
		
		return new;
end;
$$
language plpgsql;

create or replace trigger delete_cus
instead of delete on cus_view
for each row 
execute procedure delete_cus();

delete from cus_view
where id_customer < 3;

select * from cus_view
order by id_customer;


 
 
