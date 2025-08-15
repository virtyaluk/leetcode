with cte1 as (
    select
        user_id,
        round(avg(activity_duration), 2) as paid_avg_duration
    from
        UserActivity
    where
        activity_type = 'paid'
    group by
        user_id
),
cte2 as (
    select
        user_id,
        round(avg(activity_duration), 2) as trial_avg_duration
    from
        UserActivity
    where
        activity_type = 'free_trial'
    group by
        user_id
)

select
    a.user_id,
    b.trial_avg_duration,
    a.paid_avg_duration
from
    cte1 as a
left join
    cte2 as b
on
    a.user_id = b.user_id
where
    a.paid_avg_duration is not null
order by
    1