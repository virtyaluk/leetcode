# Write your MySQL query statement below
(
    select
        u.name as results
    from
        Users u
    join
        MovieRating mr
    on
        u.user_id = mr.user_id
    group by
        mr.user_id
    order by
        count(mr.movie_id) desc, u.name
    limit 1
)

union

(
    select
        m.title as results
    from
        Movies m
    join
        MovieRating mr
    on
        m.movie_id = mr.movie_id
    where
        mr.created_at like '2020-02%'
    group by
        mr.movie_id
    order by
        avg(mr.rating) desc, m.title
    limit 1
)