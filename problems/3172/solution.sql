# Write your MySQL query statement below
with cte as (
    select
        *
    from
        texts
    where
        signup_action = 'Verified'
)

select
    a.user_id
from
    emails a
left join
    cte b
using(email_id)
where
    date(a.signup_date + interval 1 day) = date(b.action_date)
order by
    1