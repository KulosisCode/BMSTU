--defend
select * from housewares
where id_customer = 1 or id_brand = 1


--1. Инструкция SELECT, использующая предикат сравнения. 
--Выбирайте предметы стоимостью не более 2000
select housewares.id, housewares.name, housewares.price
from housewares
where housewares.price <= 2000;

--2. Инструкция SELECT, использующая предикат BETWEEN.
select housewares.id, housewares.name, housewares.price, housewares.date_sale 
from housewares
where housewares.price between 1000 and 2000;

--3. Инструкция SELECT, использующая предикат LIKE.
select housewares.id, housewares.name, housewares.price, housewares.date_sale 
from housewares
where housewares.name like 'T%';

--4. Инструкция SELECT, использующая предикат IN с вложенным подзапросом.
select housewares.id, housewares.name, housewares.price, brands.brand_name  
from housewares join brands on (housewares.id_brand = brands.id_brand)
where brands.brand_name  in (select brands.brand_name from brands where id_brand <= 20);

--5. Инструкция SELECT, использующая предикат EXISTS с вложенным подзапросом.
select housewares.id, housewares.name, housewares.price, customers.first_name
from housewares join customers on (housewares.id_customer = customers.id_customer)
where exists (select housewares.name from housewares where customers.first_name = 'Juan');

--6. Инструкция SELECT, использующая предикат сравнения с квантором
select housewares.id, housewares.name, housewares.price, housewares.date_sale 
from housewares
where housewares.name = 'Couch' and housewares.price > all
(
select housewares.price 
from housewares
where housewares.name = 'Toaster'
);

--7. Инструкция SELECT, использующая агрегатные функции в выражении столбцов
select count(housewares.name)
from housewares
where housewares.name = 'Torch';

--8. Инструкция SELECT, использующая скалярные подзапросы в выражении столбцов
select customers.id_customer, customers.first_name ,
(select count(housewares.id_customer)
from housewares
where housewares.id_customer = customers.id_customer) as number_buying
from customers;

--9. Инструкция SELECT, использующая простое выражение case
select id_customer, first_name, sex,age,
								case age
								when (select max(age) 
				  					from customers) then 'Пожилой'
								when (select min(age)
				  					from customers)	then 'Молодой'
								else 'Взрослый'
								end as comment
from customers
order by age;
								
--10. Инструкция SELECT, использующая поисковое выражение case
select housewares.id, housewares.name, housewares.date_sale,
				case
					when housewares.price < 2000 then 'Дешевая'
					when housewares.price > 5000 then 'Дорогая'
					else 'Средняя'
				end as price_level
from housewares;
								
--11. Создание новой временной локальной таблицы из результирующего набора данных инструкции SELECT
drop table if exists newtable;
select customers.age, count(customers.id_customer)
into newtable
from customers
group by customers.age
order by customers.age;
select * from newtable;
								
--12. Интсрукция SELECT, использующая вложенные коррелированные подзапросы в качестве производных таблиц в предложении FROM						
select brands.id_brand, brands.brand_name, H.price
from brands join (select housewares.id_brand, housewares.price
								from housewares
								where housewares.price > 2000) as H on brands.id_brand = H.id_brand;
								
--13. Инструкция SELECT, использующая вложенные подзапросы с уровнем вложенности 3
select *
from brands
where id_brand in (select stores.id_brand
					from stores
					join housewares on housewares.id_store = stores.id_store
					group by stores.id_store
					having avg(price) = (select max(P)
										from (select avg(price) as P
												from housewares
												group by id_store) as OD)	
					);					
								
--14. Инструкция SELECT, консолидирующая данные с помощью предложения GROUP BY, но без предложения HAVING
select housewares.id_brand, count(housewares.id)
from housewares
group by housewares.id_brand;

--15. Инструкция SELECT, консолидирующая данные с помощью предложения GROUP BY, и предложения HAVING
select customers.age, count(customers.sex)
from customers
group by customers.age
having customers.age >30
order by customers.age;

--16. Однострочная инструкция INSERT,
--выполняющая вставку в таблицу одной строки значений.
insert into brands(id_brand, brand_name, country, founder)
values (1001, 'Sony', 'VietNam', 'VanHao');
	
--17. Многострочная инструкция INSERT, выполняющая вставку в таблицу результирующего набора данных вложенного подзапроса.
insert into brands(id_brand, brand_name , country, founder)
select id_brand * 1000, brand_name , country, founder
from brands
where brand_name  = 'Owens Ltd' and id_brand <10;

--18. Простая инструкция UPDATE
update housewares 
set price = price * 0.8
where id = 10;

--19. Инструкция UPDATE со скалярным подзапросом в предложении SET
update housewares 
set price = 
(
	select min(price)
	from housewares 
)
where id = 5;
								
--20. Простая инструкция DELETE
delete from brands
where id_brand = 1001;

--21. Инструкция DELETE с вложенным коррелированным подзапросом в предложении WHERE
delete from housewares  
where id in
(
	select id
	from housewares
	where price = 2000
);
			
--22. Инструкция SELECT, использующая обобщенное табличное выражение
with one (country, founder) as
(
	select country, founder
	from brands
)
select * from one;
								
--23. Инструкция SELECT, использующая рекурсивное обобщенное табличное выражение
drop table if exists testTable;
create table testTable
(
	UserID INT not null,
	Post VARCHAR(50),
	ManagerID INT
);
insert into testTable values
(1, 'Директор', NULL),
(2, 'Главный бухгалтер', 1),
(3, 'Бухгалтер', 2),
(4, 'Начальник отдела продаж', 1);

with recursive TestCTE(UserID, Post, ManagerID, LevelUser) as
   (    
        -- Находим якорь рекурсии
        select UserID, Post, ManagerID, 0 as LevelUser 
        from TestTable where ManagerID is null
        union all
        --Делаем объединение с TestCTE (хотя мы его еще не дописали)
        select t1.UserID, t1.Post, t1.ManagerID, t2.LevelUser + 1 
        from TestTable t1 join TestCTE t2 on t1.ManagerID=t2.UserID
   )
select * from TestCTE order by LevelUser

--24. Оконные функции. Использование конструкций MIN/MAX/AVG OVER()								
select id, name, price, date_sale , min(price) over (partition by date_sale) as min_in_day
from housewares
order by date_sale 

--25. Оконные функции для устранения дублей
drop table if exists dupl_test;
create table dupl_test
(
	id INTEGER,
	name VARCHAR,
	location VARCHAR
);

insert into dupl_test(id, name, location) values
(0, 'Арчи', 'дом'),
(1, 'Буч', 'улица'),
(2, 'Арчи', 'дом'),
(3, 'Патрик', 'улица');

delete from dupl_test *
where id in (select id
			from (select id, row_number () over (partition by name, location) as rown
				  from dupl_test) as t
			where t.rown > 1);
select * from dupl_test;

--допонительный
drop table if exists table1;
drop table if exists table2;
create table table1
(
	id INT NOT NULL,
	var1 VARCHAR(10),
	valid_from_dttm DATE,
	valid_to_dttm DATE
);

create table table2
(
	id INT NOT NULL,
	var2 VARCHAR(10),
	valid_from_dttm DATE,
	valid_to_dttm DATE
);

INSERT INTO table1 (id, var1, valid_from_dttm, valid_to_dttm)
VALUES (1, 'A', '2018-09-01', '2018-09-15'),
		(1, 'B', '2018-09-16', '5999-12-31');
		
INSERT INTO table2 (id, var2, valid_from_dttm, valid_to_dttm)
VALUES (1, 'A', '2018-09-01', '2018-09-18'),
		(1, 'B', '2018-09-19', '5999-12-31');

SELECT t1.id, t1.var1, t2.var2, 
		GREATEST(t1.valid_from_dttm, t2.valid_from_dttm) as valid_from_dttm,
		LEAST(t1.valid_to_dttm, t2.valid_to_dttm) as valid_to_dttm
FROM table1 as t1, table2 as t2
WHERE t1.id = t2.id AND t1.valid_from_dttm <= t2.valid_to_dttm
		AND t2.valid_from_dttm <= t1.valid_to_dttm								
								
								
								
								
								
								
								
								
								
								
								
								
								