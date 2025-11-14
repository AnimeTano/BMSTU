/*CREATE DATABASE library;*/


CREATE TABLE authors(
	id INT PRIMARY KEY,
	name VARCHAR(100),
	year_of_birth INT
);


CREATE TABLE users(
	id INT PRIMARY KEY,
	name VARCHAR(100),
	date_of_registration DATE
);


CREATE TABLE books(
	id INT PRIMARY KEY,
	title VARCHAR(100),
	author_id INT,
	year_of_publication INT,
	genre VARCHAR(100),

	FOREIGN KEY (author_id) REFERENCES authors(id)
);


CREATE TABLE borrowed_books(
	user_id INT,
	book_id INT,
	date_of_borrow DATE,
	date_of_return DATE,

	FOREIGN KEY (user_id) REFERENCES users(id),
	FOREIGN KEY (book_id) REFERENCES books(id)
);