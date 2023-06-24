# Write your MySQL query statement below
select
    min(abs(a.x - b.x)) as shortest
from
    Point a,
    Point b
where
    a.x != b.x