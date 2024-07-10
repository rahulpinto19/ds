select a1.machine_id ,round(avg( a1.timestamp - a2.timestamp ),3) as  processing_time
from
Activity a1
inner join
Activity a2
on a1.process_id = a2.process_id
and a1.machine_id = a2.machine_id
and a1.timestamp > a2.timestamp 
group by machine_id
