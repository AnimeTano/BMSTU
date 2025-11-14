INSERT INTO authors (id, name, year_of_birth) VALUES
(1, 'Лев Толстой', 1828),
(2, 'Федор Достоевский', 1821),
(3, 'Антон Чехов', 1860);


INSERT INTO books(id, title, author_id, year_of_publication, genre) VALUES
(1, 'Война и мир', 1, 1869, 'Роман-эпопея'),
(2, 'Преступление и наказание', 2, 1866, 'Роман'),
(3, 'Вишнёвый сад', 3, 1904, 'Пьеса'),
(4, 'Три сестры', 3, 1901, 'Пьеса'),
(5, 'Дядя Ваня', 3, 1899, 'Пьеса'),
(6, 'Палата №6', 3, 1892, 'Рассказ');



INSERT INTO users (id, name, date_of_registration) VALUES
(1, 'Иван Петров', '2023-01-15'),
(2, 'Мария Сидорова', '2023-02-20'),
(3, 'Алексей Иванов', '2023-03-10');


INSERT INTO borrowed_books (user_id, book_id, date_of_borrow, date_of_return) VALUES
(1, 1, '2024-01-10', '2024-01-25'),
(2, 2, '2024-01-15', NULL),
(3, 3, '2024-01-20', '2024-02-05');