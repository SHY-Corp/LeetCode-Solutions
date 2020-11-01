SELECT wankhede.* FROM stadium wankhede                                               /* Selecting Column and renaming it */
    LEFT JOIN stadium p1 ON wankhede.id - 1 = p1.id                                   /* join conditions */      
    LEFT JOIN stadium p2 ON wankhede.id - 2 = p2.id
    LEFT JOIN stadium n1 ON wankhede.id + 1 = n1.id
    LEFT JOIN stadium n2 ON wankhede.id + 2 = n2.id
WHERE (wankhede.people >= 100 AND p1.people >= 100 AND p2.people >= 100)               /* checking necessary conditions */
     OR (wankhede.people >= 100 AND n1.people >= 100 AND n2.people >= 100)
     OR (wankhede.people >= 100 AND n1.people >= 100 AND p1.people >= 100)
ORDER BY id;                                                                            /* ordering the result */
