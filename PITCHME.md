### Vulnerability and Exploitation
### (with Onion Messengers)

<br>
<br>

- TA: SeongIl Wi
- DongHyeon Oh

---

## Goals

<br>
<br>

- Logic error : people all make mistakes sometimes |
- Command injection : victim should not be aware |
- Privacy breach : get a sensitive data |

---

## Scenario

- Logic error ->
- Control-flow hijack(Command injection) ->
- Privacy breach
- In a broad sense,
  command injection is control-flow hijack

---

## Logic error

![logic1](images/logic1.png)

---

## Logic error


---?code=assets/logic1.cpp&lang=c++&title=Recv thread source

@[1-5](Key alive)
@[6-10](Key die)
@[11-49](Get my message)
@[50-54](Not my message. So forwarding)

---

## Logic error

![logic2](images/logic2.png)

---

## Logic error

![logic3](images/logic3.png)

---

## Command injection

![cmdi1](images/cmdi1.png)

---

## Command injection

![cmdi2](images/cmdi2.png) 

---

## Privacy breach

---?code=assets/privacy.cpp&lang=c++&title=pgpgmanaer.cpp

@[3,7,21](There is a term)

---

## Demo

---

## Summary

<br>

- Logic error

- Control-flow hijack

- Privacy breach

---

# Q & A

