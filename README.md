# alfred-workflow-cpp

```bash
brew install cmake
brew install autoconf automake autoconf-archive libtool

~/vcpkg/vcpkg x-update-baseline --add-initial-baseline
```

## vscode로 프로젝트 열기

```bash
cmake --list-presets
cmake --preset release && cmake --build --preset release-build

./bin/Release/open_project_in_vscode bin/Release/vscode_project
```

* [x] 프로젝트 세팅 (VSCode, cmake, vcpkg, ...)
* [x] 파일 경로를 입력 받아서 출력
* [x] local, remote 경로를 구현하는 `Project` 인터페이스 구현체 추가
* [x] 여러개의 검색어 가능
* [x] alfred workflow output(json) 형태로 출력
* [x] alfred worlfow 연동
* [x] score, sort 추가. keywords가 가장 많이 매칭되는 순서
* [x] ParameterizedTest 테스트 추가
* ~~[ ] coroutine 적용~~
    * c++20의 coroutine은 기본적으로 싱글스레드. 내가 생각했던 kotlin+coroutine처럼 dispatcher에 의해 스레드 할당이 이뤄지기 위해서는 별도의 비동기, 스레드풀 관리 추가 작업이 필요하다.
    * Folly, libuv 같은 서드파티 라이브러리를 사용하는게 추천된다

## 복사하면 문자열에 따라서 특정 액션 수행

* url 형태라면 크롬에서 오픈
* 커맨드 형태라면 커맨드만 따서 클립보드에 복사

## url 한꺼번에 열기

특정 경로에 key: URL 링크들. 구조의 파일이 있다
key 목록을 보여주고 key를 선택했을때 URL 링크들이 모두 열린다
