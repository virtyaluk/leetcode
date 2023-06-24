# Write your MySQL query statement below
select
    Users.user_id as buyer_id,
    Users.join_date,
    COALESCE(count(order_date), 0) as orders_in_2019
from
    Users
left join
    Orders
on
    Users.user_id = Orders.buyer_id and year(order_date) = 2019
group by
    user_id