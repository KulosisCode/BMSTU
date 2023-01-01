-- 1  извлечение данных в JSON

create or replace procedure backup()
language plpgsql
as $$
declare 
	t text;
	query text;
begin
	for t in
		select table_name
		from information_schema."tables"
		where table_schema  = 'public'
	loop
		query := 	'copy (select row_to_json(r) from ' || t ||
					' as r) to ''D:\PROGRAM\HK5\DB\LAB5\' || t ||
					'.json''';
		raise notice '%', query;
	execute query;
		
	end loop;
	
end
$$

call backup()

select * from information_schema."tables"
where table_schema  = 'public';


-- 2.загрузка и сохранение JSON в таблицу

create temp table json_tab(json_t json);

copy json_tab from 'D:\PROGRAM\HK5\DB\LAB5\brands.json';

create table if not exists br_copy
(
	id_brand INT primary key, 
	brand_name text,
	country text,
	founder text
);

insert into br_copy
select j.*
from json_tab cross join lateral json_populate_record(null::br_copy, json_t) as j

--вспомогательные запросы
select * from json_tab;

--select (json_t->>'id_brand') :: int,
--       json_t->>'brand_name',
--       json_t->>'country',
--       json_t>>'founder'
--from json_tab;

select * from br_copy
order by id_brand;

select * from brands
order by id_brand;

drop table br_copy;
drop table json_tab;

-- 3. Создать таблицу с атрибутами типа JSON (или добавить к существующей столбец)
alter table housewares 
add column json_tab json;

-- Добавляем данные JSON
update housewares 
set json_tab = '{"color":"blue", "Weight":"heavy", "Unbox":"yes"}'
where id_brand  in (select id_brand
                from brands 
                where country = 'Anguilla');

update housewares 
set json_tab = '{"color":"blue", "Weight":"light", "Unbox":"no"}'
where id_brand  in (select id_brand
                from brands 
                where country = 'Poland');

select * from housewares;

-- 4. Выполнить следующие действия:

-- Извлечь XML/JSON фрагмент из XML/JSON документа
-- Извлечь значения конкретных узлов или атрибутов JSON документа
create table temp_table(data json)

copy temp_table
from 'D:\PROGRAM\HK5\DB\LAB5\brands.json'

select * from temp_table;

drop table if exists json_test;
create table json_test(
	country text,
	founder text
)

insert into json_test(country, founder)
select data->>'country', data->>'founder'
from temp_table
where data->>'founder' like '%ela%';

select * from json_test;

--Выполнить проверку существования узла или атрибута
select * from housewares 
where json_extract_path(json_tab, 'colo') is not null; 


-- Изменить XML/JSON документ
update json_test
set founder = founder || '-Adrian'
where country like 'T%'

-- Разделить XML/JSON документ на несколько строк по узлам
drop table if exists json_test_2;
create table json_test_2(
    houseware text,
    info json);

insert into json_test_2 (houseware, info)
values ('Wash machine', '[{"color":"red", "Weight":"heavy", "Unbox":"yes"}, {"color":"blue", "Weight":"light", "Unbox":"no"}]');

select *
from json_test_2;

select houseware, json_array_elements(info)
from json_test_2;