#ifndef AUTH
#define AUTH
class State;
class Authorization
{
private:
	State* state;
public:
	void doAuth();
	friend class Yes;
	friend class No;
};
class State
{
public:
	virtual void sDoAuth(Authorization*) = 0;
};
class Yes : public State
{
public:
	virtual void sDoAuth(Authorization*auth)override
	{
		auth->state = new Yes();
	}
};
class No : public State
{
public:
	virtual void sDoAuth(Authorization*auth)override
	{
		auth->state = new No();
		exit(0);
	}
};
void Authorization::doAuth() { state->sDoAuth(this); }
#endif