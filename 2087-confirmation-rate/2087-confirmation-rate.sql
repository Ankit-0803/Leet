# Write your MySQL query statement below
select s.user_id, 
round(coalesce(sum(case when action='confirmed' then 1 end)/count(*),0),2) as confirmation_rate
from Signups s
left join confirmations c on s.user_id=c.user_id
group by user_id