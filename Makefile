DIRS = ch02 ch04 ch05 ch06 ch08

all:
	@$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) && cd .. &&) true;

clean:
	@$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) clean && cd .. &&) true;

clobber:
	@$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) clobber && cd .. &&) true;
