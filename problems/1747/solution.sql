# Write your MySQL query statement below
with cte as (select * from LogInfo where logout > login)

select
    distinct a.account_id
from
    cte a
left join
    cte b
on
    a.account_id = b.account_id and a.ip_address != b.ip_address
where a.login between b.login and b.logout