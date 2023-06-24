# Write your MySQL query statement below
select t.sale_date, t.minus as diff
from
(
select a.sale_date as sale_date, (a.sold_num-b.sold_num) as minus
from Sales a join Sales b
on a.sale_date=b.sale_date and b.fruit='oranges'
and a.fruit='apples'
group by a.sale_date
) t
order by t.sale_date
;