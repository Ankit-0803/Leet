# Write your MySQL query statement below
select machine_id, round(avg(end-start), 3) as processing_time from
    (select machine_id, 
    process_id,
     MAX(CASE WHEN activity_type = 'start' THEN timestamp END) AS start,
    MAX(CASE WHEN activity_type = 'end' THEN timestamp END) AS end
    from activity
    group by machine_id, process_id)as subq
    group by machine_id;
