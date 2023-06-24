# Write your MySQL query statement below
with ame as (
    select
        name as America,
        row_number() over(order by name) as rn
    from
        Student
    where
        continent = 'America'
),
asi as (
    select
        name as Asia,
        row_number() over(order by name) as rn
    from
        Student
    where
        continent = 'Asia'
),
eur as (
    select
        name as Europe,
        row_number() over(order by name) as rn
    from
        Student
    where
        continent = 'Europe'
)

select
    America,
    Asia,
    Europe
from
    ame a
left join
    asi
on
    a.rn = asi.rn
left join
    eur
on
    a.rn = eur.rn