# Write your MySQL query statement below
select player_id , event_date as first_login from activity a where event_date = (select min(event_date) from activity where a.player_id = player_id );