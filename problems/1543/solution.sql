select
    trim(lower(product_name)) as product_name,
    left(sale_date, 7) as sale_date,
    count(*) as total
from
    Sales
group by
    1, 2
order by
    1 asc, 2 asc