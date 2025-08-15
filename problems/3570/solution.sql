# Write your MySQL query statement below
select
    lb.book_id,
    lb.title,
    lb.author,
    lb.genre,
    lb.publication_year,
    cb.current_borrowers
from
    library_books lb
right join
    (
        select
            book_id,
            count(*) as current_borrowers
        from
            borrowing_records
        where
            return_date is null
        group by
            book_id
    ) cb
    on
    lb.book_id = cb.book_id
where
    lb.total_copies = cb.current_borrowers
order by
    cb.current_borrowers desc,
    lb.title asc;