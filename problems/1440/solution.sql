# Write your MySQL query statement below
select
    e.left_operand,
    e.operator,
    e.right_operand,
    (
        case
            when e.operator = '>' and v1.value > v2.value then 'true'
            when e.operator = '<' and v1.value < v2.value then 'true'
            when e.operator = '=' and v1.value = v2.value then 'true'
            else 'false'
        end
    ) as value
from
    Expressions e
join
    Variables v1
on
    e.left_operand = v1.name
join
    Variables v2
on
    e.right_operand = v2.name
    