# Write your MySQL query statement below 
select
    t1.transaction_id
from
    Transactions t1
join
    (
        select
            DATE_FORMAT(day, '%Y-%m-%d') as d,
            max(amount) as a
        from
            Transactions
        group by
            d
    ) t2
on
    DATE_FORMAT(t1.day, '%Y-%m-%d') = t2.d and t1.amount = t2.a
order by
    1 asc