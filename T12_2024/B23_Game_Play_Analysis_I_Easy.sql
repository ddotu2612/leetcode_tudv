/* Write your PL/SQL query statement below */
--C1:
select player_id, to_char(event_date, 'yyyy-MM-dd') first_login
from (
select a.*, row_number() over (partition by player_id order by event_date) rnk
from activity a
)
where rnk = 1;

--C2:
select player_id, to_char(min(event_date), 'yyyy-mm-dd') as first_login 
from activity 
group by player_id;
