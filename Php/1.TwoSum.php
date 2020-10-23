<?php

// Problem - 1. Two Sum

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

function twoSum($numbers, $target)
{
    for ($i = 0; $i < count($numbers); $i++) {            //outer loop  0 --> size of vector nums

        for ($j = 1; $j < count($numbers); $j++) {        //inner loop  1 --> size of vector nums

            if ($numbers[$i] + $numbers[$j] == $target && $i != $j)
                return [$i, $j];         // return vector of i and j if condition satisfies
        }
    }
    return [];   // return empty vector if condition fails for every element
}
