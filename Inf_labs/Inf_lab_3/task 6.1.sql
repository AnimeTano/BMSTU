SELECT name, COUNT(*) AS "Всего книг взято" FROM users
JOIN borrowed_books ON id = borrowed_books.user_id
GROUP BY id, name;