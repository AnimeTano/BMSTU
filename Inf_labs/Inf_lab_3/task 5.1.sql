/*
--По айди
SELECT * FROM books
WHERE author_id = 3;
*/


--По имени в таблице 'authors'
SELECT * FROM books
JOIN authors ON books.author_id = authors.id
WHERE authors.name = 'Антон Чехов';
