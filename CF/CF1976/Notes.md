Notes on solutions/approaches to problems

# A: Verify Password
We need all the digits to be at the front and sorted, then we need all the letters to follow and be sorted.
By ASCII values, numerical digits are smaller than letters. So, the password should be sorted by ASCII value.
Just iterate over the string, making sure every character's ASCII value is greater than or equal to the previous character's ASCII value.

# B: Increase/Decrease/Copy
Inevitably, we have to get all `a[i]` to `b[i]` and these operations cannot be avoided. This will cost us `s = sum(abs(a[i]-b[i])), for 0 <= i < n`. The question is, how do we optimize acquiring the last element `b[n]`?

There are two cases:
- Case 1: There exists an index `i` such that `a[i] <= b[n] <= b[i]`, or that `b[i] <= b[n] <= a[i]`.
- Case 2: There is no such `i` as described above.

Case 1: At some point, there will be an element in `a` that is equivalent to `b[n]`. Therefore, we just need to copy it to the end of `a` for 1 operation, but no increments or decrements are needed for `a[n]`. So our answer is `s+1`.

Case 2: We will never have `b[n]` inside of `a` during our increments decrements. So, we need to find the closest one to minimize the operations. The closest any element in `a` will be to `b[n]` will be at the start or at the end, since `b[n]` is not within the range `[a[i], b[i]]` (or `[b[i], a[i]]`). So, we take the closest element to `b[n]` among all elements `a[i], b[i], 0 <= i < n`. The absolute difference `d` between this element and `b[n]` is the number of increments/decrements we will have to spend on `a[n]` after copying. So our answer is `s+d+1`.

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
