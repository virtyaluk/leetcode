# Write your MySQL query statement below
select
    account_id,
    day,
    sum(case when type = 'Withdraw' then -amount else amount end) over(partition by account_id order by day asc) as balance
from
    Transactions