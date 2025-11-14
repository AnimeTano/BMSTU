SELECT * FROM borrowed_books
JOIN books ON borrowed_books.book_id = books.id
JOIN users ON borrowed_books.user_id = users.id
WHERE date_of_return IS NULL;