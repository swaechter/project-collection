Summary             : A C/C++ IDE
Name                : cdevstudio
Version             : 0.0.8
Release             : 8
License             : GPLv3
Source              : %{name}-%{version}.tar.gz

%description
A C/C++ IDE for Unix, Linux, OS X and Windows.

%prep
%setup

%build
%cmake ../%{name}-%{version} -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
make

%install
make install DESTDIR="%{buildroot}"

%files
/usr/bin/cdevstudio
/usr/share/applications/cdevstudio.desktop
/usr/share/man/man1/cdevstudio.1.gz
/usr/lib/libcdevstudioplatform.so*
/usr/include/cdevstudioplatform/PlatformExport.h
/usr/include/cdevstudioplatform/Platform.h
/usr/include/cdevstudioplatform/IPlatform.h
/usr/include/cdevstudioplatform/PluginManager.h
/usr/include/cdevstudioplatform/PluginContainer.h
/usr/include/cdevstudioplatform/IPlugin.h
/usr/include/cdevstudioplatform/ProjectManager.h
/usr/include/cdevstudioplatform/Project.h
/usr/include/cdevstudioplatform/WindowManager.h
/usr/include/cdevstudioplatform/Window.h
/usr/include/cdevstudioplatform/Settings.h
/usr/include/cdevstudioplatform/SettingsPage.h
/usr/include/cdevstudioplatform/Backend.h
/usr/lib/libpluginproject.so*
/usr/lib/libpluginprojectexplorer.so*
/usr/lib/libplugineditor.so*
