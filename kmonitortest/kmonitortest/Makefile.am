INCLUDES = $(all_includes)

kde_module_LTLIBRARIES = kcm_kmonitortest.la
kcm_kmonitortest_la_METASOURCES=AUTO
kcm_kmonitortest_la_SOURCES = kmonitortest.cpp
kcm_kmonitortest_la_LIBADD = $(LIB_KDEUI) $(LIB_KDECORE) $(LIB_QT)
kcm_kmonitortest_la_LDFLAGS = $(all_libraries) -module $(KDE_PLUGIN)

SUBDIRS = pics


desktop_DATA = kmonitortest.desktop
desktopdir = $(kde_appsdir)/Settings/Peripherals

messages:
	$(XGETTEXT) $(kcm_kmonitortest_la_SOURCES) -o $(podir)/kmonitortest.pot