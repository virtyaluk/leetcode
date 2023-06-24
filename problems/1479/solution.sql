# Write your MySQL query statement below
with T1 as (
Select b.item_id,b.item_category, a.day_of_week, total
from Items as b
left join
(select item_id, weekday(order_date) as day_of_week, sum(quantity) as total
from Orders
group by item_id, weekday(order_date)
) as a on a.item_id = b.item_id
)

Select
item_category as category,
sum(case when day_of_week=0 then total else 0 end ) as 'Monday',
sum(case when day_of_week=1 then total else 0 end ) as 'Tuesday',
sum(case when day_of_week=2 then total else 0 end ) as 'Wednesday',
sum(case when day_of_week=3 then total else 0 end ) as 'Thursday',
sum(case when day_of_week=4 then total else 0 end ) as 'Friday',
sum(case when day_of_week=5 then total else 0 end ) as 'Saturday',
sum(case when day_of_week=6 then total else 0 end ) as 'sunday'
from T1
group by item_category
order by item_category