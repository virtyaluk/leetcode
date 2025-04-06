# Write your MySQL query statement below
select book_id, title, author, published_year from books where isnull(rating) order by 1