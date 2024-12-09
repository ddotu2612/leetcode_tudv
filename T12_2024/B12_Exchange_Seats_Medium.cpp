/* Write your PL/SQL query statement below */
select id, 
    case when mod(id, 2) = 0 then lag(student) over(order by id)
    else coalesce(lead(student) over (order by id), student)
    end as student
from seat a
