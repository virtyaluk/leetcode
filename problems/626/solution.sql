# Write your MySQL query statement below
select
    (
        case
            when mod(id, 2) <> 0 and id != cts.counts then id + 1
            when mod(id, 2) <> 0 and id = cts.counts then id
            else id - 1
        end
    ) as id,
    s.student
from
    Seat s,
    (select count(id) as counts from Seat) as cts
order by
    id