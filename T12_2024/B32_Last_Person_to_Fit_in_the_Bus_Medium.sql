/* Write your PL/SQL query statement below */
-- WITH CumulativeSum AS (
--     SELECT person_name, SUM(weight) OVER (ORDER BY turn) AS cumulative_sum
--     FROM Queue
-- )
-- select *
-- from (SELECT person_name
-- FROM CumulativeSum
-- WHERE cumulative_sum <= 1000
-- ORDER BY cumulative_sum DESC
-- ) where rownum = 1
with tw as (select person_name ,
       sum(weight) over (order by turn) as total_weight 
from Queue)
select person_name
from tw
where total_weight = (
       select max(total_weight)
       from tw
       where total_weight <= 1000)
