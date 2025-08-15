# Write your MySQL query statement below
with a as (
    select
        max(session_rating) as maxRating,
        min(session_rating) as minRating,
        book_id,
        round(
            sum(
                case
                    when
                        session_rating <= 2
                    then
                        1
                    when
                        session_rating >= 4
                    then
                        1
                    else
                        0
                end
            )/count(book_id),
            2
        ) as polarization_score
    from
        reading_sessions
    group by
        reading_sessions.book_id
)

select
    reading_sessions.book_id,
    title,
    author,
    genre,
    pages,
    maxRating-minRating as rating_spread,
    polarization_score
from
    reading_sessions,
    books,
    a
where
    books.book_id = reading_sessions.book_id
    and
    a.book_id = reading_sessions.book_id
    and
    maxRating > 3
    and
    minRating < 3
    and
    polarization_score >= 0.6
group by
    reading_sessions.book_id
    having count(reading_sessions.book_id) > 4
order by
    polarization_score desc,
    title desc