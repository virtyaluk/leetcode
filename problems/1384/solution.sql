with recursive cte as (
    select
        product_id,
        period_start as available_date
    from
        Sales
    union
    select
        s.product_id,
        DATE_ADD(cte.available_date, interval 1 DAY)
    from
        cte
    inner join
        Sales s
    on
        cte.product_id = s.product_id
        and
        DATE_ADD(cte.available_date, interval 1 DAY) <= s.period_end
)

select
    c.product_id,
    p.product_name,
    convert(year(c.available_date), char) as report_year,
    count(c.available_date) * average_daily_sales as total_amount
from
    cte c
join
    Product p
join
    Sales s
on
    c.product_id = p.product_id and c.product_id = s.product_id
group by 
    1, 2, 3
order by
    1, 3