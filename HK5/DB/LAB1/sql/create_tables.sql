create table if not exists brands(
	id_brand INT primary key, 
	brand_name text,
	country text,
	founder text
);


create table if not exists customers(
	id_customer INT primary key,
	first_name text,
	last_name text,
	sex text,
	age INT CHECK(age >= 15 and age <= 60),
	city text
);


create table if not exists stores(
	id_store INT primary key,
	name text,
	address text,
	
	id_brand INT,
	foreign key (id_brand) references brands(id_brand),
	
	email text
);


create table if not exists charac(
	id_type INT primary key,
	type_name text,
	description text,
	material text
);


create table if not exists housewares(
	id INT primary key,
	name text,
	price INT CHECK(price >= 50 and price <= 10000),
	date_sale DATE,
	
	id_type INT,
	foreign key (id_type) references charac(id_type),
	
	id_brand INT,
	foreign key (id_brand) references brands(id_brand),
	
	id_customer INT,
	foreign key (id_customer) references customers(id_customer),
	
	id_store INT,
	foreign key (id_store) references stores(id_store)
);
