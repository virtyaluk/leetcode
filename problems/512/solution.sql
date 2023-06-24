# Write your MySQL query statement below
# with cte as (
#     select
#         player_id,
#         device_id,
#         row_number() over(partition by player_id order by event_date asc) as rn
#     from
#         Activity
# )

# select
#     player_id,
#     device_id
# from
#     cte
# where
#     rn = 1

select
    distinct player_id,
    first_value(device_id) over(partition by player_id order by event_date asc) as device_id
from
    Activity