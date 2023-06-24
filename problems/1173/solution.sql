# Write your MySQL query statement below
select
    round(
        sum(case when order_date = customer_pref_delivery_date then 1 else 0 end)
        / count(delivery_id)
        * 100,
    2) as immediate_percentage
from Delivery