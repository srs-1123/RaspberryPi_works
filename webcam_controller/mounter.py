import subprocess

# マウントするホスト側ディレクトリとRaspberry Pi側ディレクトリ
def mount_dir(host_dir, remote_dir):
    # SSHFSコマンドの実行
    user_name = "pi"
    ip_address = "192.168.128.198"
    command = ['sshfs', '-o', 'allow_other', '-o', 'follow_symlinks', '-o', 'IdentityFile=/path/to/ssh/key', f'{user_name}@{ip_address}:{host_dir}', remote_dir]
    subprocess.run(command)

# これでいける？
    sshfs username@server:/pi側ディレクトリ/ ~/windows側ディレクトリ