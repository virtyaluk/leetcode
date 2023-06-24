# Write your MySQL query statement below
with cte as (
    select
        *,
        rank() over(partition by gender order by user_id) as rn1,
        if(gender = 'female', 0, if (gender='other', 1, 2)) as rn2
    from
        Genders
)

select
    user_id,
    gender
from
    cte
order by
    rn1, rn2