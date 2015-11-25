all: build
	@echo Done.

build:
	$(MAKE) -C submodules/bm VERBOSE=1
	$(MAKE) -C $(CURDIR)/targets/basic_routing/bmv2 bm VERBOSE=1

clean:
	$(MAKE) -C $(CURDIR)/submodules/bm clean
	$(MAKE) -C $(CURDIR)/submodules/p4c-bm/pd_mk clean
	$(MAKE) -C $(CURDIR)/targets/basic_routing/bmv2 clean

distclean: clean
	$(MAKE) -C $(CURDIR)/submodules/bm distclean
	$(MAKE) -C $(CURDIR)/submodules/p4c-bm/pd_mk distclean

.PHONY: all build clean distclean
