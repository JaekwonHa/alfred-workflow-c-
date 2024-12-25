# alfred-workflow-cpp

```bash
brew install cmake
brew install autoconf automake autoconf-archive libtool

~/vcpkg/vcpkg x-update-baseline --add-initial-baseline
```

## vscode로 프로젝트 열기

```bash
cmake --list-presets
cmake --preset release
cmake --build --preset release-build

./bin/Release/open_project_in_vscode bin/Release/vscode_project
```

* [x] 프로젝트 세팅 (VSCode, cmake, vcpkg, ...)
* [x] 파일 경로를 입력 받아서 출력
* [x] local, remote 경로를 구현하는 `Project` 인터페이스 구현체 추가
* [ ] `isMatched` 함수 구현. 여러개의 검색어 가능
* [ ] `print` 함수 구현. alfred workflow output(json) 형태로 출력
* [ ] alfred worlfow 연동
* [ ] coroutine 적용

## 복사하면 문자열에 따라서 특정 액션 수행

* url 형태라면 크롬에서 오픈
* 커맨드 형태라면 커맨드만 따서 클립보드에 복사

## url 한꺼번에 열기

특정 경로에 key: URL 링크들. 구조의 파일이 있다
key 목록을 보여주고 key를 선택했을때 URL 링크들이 모두 열린다
