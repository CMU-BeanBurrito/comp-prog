Notes on solutions/approaches to problems

# A: Verify Password

# B: Increase/Decrease/Copy

# C: Job Interview
*explanation is 0-indexed

If all candidates show up, the last candidate, the (`n+m`)th candidate will not be hired in any role.
Simulate the hiring process under this premise, computing the role of each of the first `n+m` candidates, as well as the skill of the team `s`. (Observe that this sum `s` is `ans[n+m]`.)
Also, find the first candidate that gets hired to the role they are worse at, call this index `bad`.

Claim: the `bad`th candidate is the only one whose role can change if someone doesn't show up.

Proof:

Without loss of generality, assume the `bad`th candidate is better at programming but was hired as a tester.

Clearly, any candiate `c` hired before the `bad`th candidate is unaffected if another doesn't show up. If the no-show is before `c`, `c` already got their optimal role. If the no-show is after `c`, `c` has already been hired.

What about candidates `c` hired after `bad`? Suppose `c` is better at programming. Since there were already enough programmers when `bad` got hired, `c` will be hired as a tester.
If the no-show is before `bad` and was going to be hired as a programmer, then `bad` will get the programmer role they wanted, and `c` will still be a tester.
If the no-show is before `bad` and was going to be hired as a tester, then `bad` and `c` will still be testers.
If the no-show is between `bad` and `c`, and was going to be hired as a programmer? Not possible, as everyone after `bad` was going to be hired as a tester.
If the no-show is between `bad` and `c`, and was going to be hired as a tester, everyone after `bad`, including `c` will be a tester.
If the no-show is after `c`, `c` was already hired as a tester.

So, if the `i`th candidate does not show, we need to find `ans[i]` in relation to `s`.

Let's create 3 cases:
- Case 1: `i < bad` AND `role[i] != role[bad]`
- Case 2: `i < bad` AND `role[i] == role[bad]`
- Case 3: `i >= bad` 

Case 1:

We begin with `s` as the team's skill. Since candidate `i` is not showing up, we need to remove candidate `i`'s contribution to the team's skill.
Because `role[i] != role[bad]`, it means that `bad` can now get their optimal role. So adjust `bad`'s contribution to the team's skill.
Candidate `n+m` can now be hired, but only `bad`'s original role will be left. So add `n+m`'s skill to the team.
Overall: `ans[i] = s - skill[i] + bad's preferred skill - bad's unpreferred skill + n+m's skill at bad's unpreferred role`

Case 2 and Case 3 will both result in the same actions, explanation:

Case 2:
We begin with `s` as the team's skill. Since candidate `i` is not showing up, we need to remove candidate `i`'s skill from the team.
Because `role[i] == role[bad]`, it means that `bad`'s role will not change.
Candidate `n+m` can now be hired, but only `i`'s role will be left. So add `n+m`'s skill to the team.
Overall: `ans[i] = s - skill[i] + n+m's skill at i's role`

Case 3:
We begin with `s` as the team's skill. Since candidate `i` is not showing up, we need to remove candidate `i`'s skill from the team.
Because `i >= bad`, `bad`'s role is not affected.
Candidate `n+m` can now be hired, but only `i`'s role will be left (this is the same as `bad`'s role).
Overall: `ans[i] = s - skill[i] + n+m's skill at i's role`

There is one edge case we have to consider. If the first `n+m` candidates all get their preferred role on the initial iteration, there is no `bad` candidate. So, when we iterate to find `ans[i]`, candidate `n+m` will always get candidate `i`'s role (this is case 2/3).

# D: Invertible Bracket Sequences

# E: Splittable Permutations

# F: Remove Bridges
