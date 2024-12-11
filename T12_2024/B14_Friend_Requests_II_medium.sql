/* Write your PL/SQL query statement below */
select id, num
from(
select id, count(*) num, dense_rank() over (order by count(*) desc) rnk
from (
select requester_id id, accept_date
from RequestAccepted a
union all
select accepter_id id, accept_date
from RequestAccepted a
)
group by id
)
where rnk = 1
