Summary             : A testapplication based on the Qt5 framework
Name                : testapplication
Provides            : testapplication
Version             : 0.1.0
Release             : 1%{?dist}
License             : GPLv3
Source              : %{name}-%{version}.tar.gz
BuildRequires       : cmake qt-devel qt5-qtbase-devel qt5-qttools-devel
Requires            : qt5-qtbase qt5-qttools

%description
A C/C++ testapplication for Unix, Linux, OS X and Windows.

%prep
%setup

%build
cmake -DCMAKE_SKIP_RPATH=ON -DCMAKE_INSTALL_PREFIX=%{_prefix}
make

%install
make install DESTDIR=%{buildroot}

%files
/usr/bin/testapplication
%_libdir/libsharedlibrary.so
%_libdir/libsharedlibrary.so.0
%_libdir/libsharedlibrary.so.0.1.0
%_libdir/libstaticlibrary.a
/usr/include/SharedLibrary.h
/usr/include/SharedLibraryExport.h
/usr/include/StaticLibrary.h
/usr/share/applications/testapplication.desktop
/usr/share/man/man1/testapplication.1.gz
