select * from brands;
select * from charac;
select * from customers;
select * from stores;
select * from housewares order by id;

--test lab 6

select * from customers where customers.age in (select min(age) from customers);

select housewares.name, housewares.price, customers.age
                    from housewares join customers on housewares.id_customer = customers.id_customer
                    where housewares.price < 5000 and customers.age < 20;
                
select id_brand, id_store, price, 
                    avg(price) over (partition by id_brand) as avg_brand_price, 
                    min(price) over (partition by id_brand order by id_store) as min_brand_price, 
                    max(price) over (partition by id_store) as max_store_price 
                    from housewares
                    
drop table if exists expired;
create table public.expired(
                id int generated always as identity primary key,
                name text not null, price int not null)
                
select * from expired ;


insert into expired(name, price) values 
                        ('Big TV', 1500), 
                        ('Moonlike light', 1000), 
                        ('Telephone',2000); 
                        select * from expired;
                        
                       
--testing for lab_7
                       
select brand_name  from brands b ;
select brand_name founder from brands where country  = 'Bhutan'

drop database  if exists  rk_3;
create database rk_3;

create database rk_2;