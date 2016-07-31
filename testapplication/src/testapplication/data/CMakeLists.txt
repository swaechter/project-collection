if(UNIX)
	install(FILES desktop/testapplication.desktop DESTINATION ${PROJECT_DESKTOP_PREFIX})
	install(FILES man/testapplication.1.gz DESTINATION ${PROJECT_MAN_PREFIX})
endif()
