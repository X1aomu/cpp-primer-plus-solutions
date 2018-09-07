DIRS = ch02

all:
	@$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) && cd .. &&) true;

clean:
	@$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) clean && cd .. &&) true;

clobber:
	@$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) clobber && cd .. &&) true;
