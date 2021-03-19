# SnapchUTT
This repository is linked to a student project.

The objective is to create a little social network.  
We are going to use a simplified database of a social network.
Student user is characterized by :
  Full-name : First name + last name.
  Age.
  Year of study.
  City of residence.
  Areas of interests.

A student can follow many other student.

In order to implement this and simplify the search of users, we use an array of
length 26 (an entry for each letter of the alphabet) and
where each entry points to a list of users
whose names start with the corresponding letter.
Each element of this list is a structure of users that contains its information
and a pointer to a list of users that this user follows
(this list should be ordered alphabetically).

There is 5 features to add :
1. Insertion, deletion and updating users.
2. Adding followers to a user’s followers list. (Follow feature)
3. Display all the followers of a certain user.
4. Search for users by name, field, year of study and areas of interest.
5. Propose a list of user suggestions for a certain user to follow,
this list is limited to the top 5 users according to the following two criteria:
— Mutual interests : These are the users with the most shared interests.
— Mutual contacts : These are the users that repeat the most in the list
of followers of the user’s followers.

BONUS FEATURE : Export the list of users with their corresponding followers to
a file and import it to continue the next time.
