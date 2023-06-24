# Write your MySQL query statement below
with recursive cte as (
    select task_id, 1 as subtask_id from Tasks
    union all
    select task_id, subtask_id + 1 from cte join Tasks using(task_id) where subtask_id < subtasks_count
)

select
    task_id,
    subtask_id
from
    cte
where
    (task_id, subtask_id) not in (select * from Executed)